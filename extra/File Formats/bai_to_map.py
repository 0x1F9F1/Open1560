import struct
import numpy

def read_unpack(file, fmt):
    return struct.unpack(fmt, file.read(struct.calcsize(fmt)))

class Vector3:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def read(file):
        return Vector3(*read_unpack(file, '<3f'))

    def readn(file, count):
        return [ Vector3.read(file) for _ in range(count) ]

    def __repr__(self):
        return '{{{:f},{:f},{:f}}}'.format(self.x, self.y, self.z)

    def __add__(self, other):
        return Vector3(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vector3(self.x - other.x, self.y - other.y, self.z - other.z)

    def __mul__(self, other):
        return Vector3(self.x * other, self.y * other, self.z * other)

    def __eq__(self, other):
        return (self.x, self.y, self.z) == (other.x, other.y, other.z)

    def Mag2(self):
        return (self.x * self.x) + (self.y * self.y) + (self.z * self.z)

    def Dist2(self, other):
        return (other - self).Mag2()

class aiPath:
    def load(self, file):
        self.ID,\
        self.NumVertexs,\
        self.NumLanes,\
        self.NumSidewalks,\
        self.StopLightIndex,\
        self.IntersectionType,\
        self.Blocked,\
        self.PedBlocked,\
        self.Divided,\
        self.IsFlat,\
        self.HasBridge,\
        self.Alley,\
        self.RoadLength,\
        self.SpeedLimit,\
        self.StopLightName,\
        self.OppositeID,\
        self.EdgeIndex,\
        self.PathIndex = read_unpack(file, '<HHHHHHHHHHHHff32sIII')
        self.SubSectionOffsets = read_unpack(file, '<{}f'.format(self.NumVertexs * (self.NumLanes + self.NumSidewalks)))
        self.CenterOffsets = read_unpack(file, '<{}f'.format(self.NumVertexs))
        self.IntersectionIds = read_unpack(file, '<2I')
        self.LaneVertices = Vector3.readn(file, self.NumVertexs * (self.NumLanes + self.NumSidewalks))
        self.CenterVertices = Vector3.readn(file, self.NumVertexs)
        self.VertXDirs = Vector3.readn(file, self.NumVertexs)
        self.Normals = Vector3.readn(file, self.NumVertexs)
        self.VertZDirs = Vector3.readn(file, self.NumVertexs)
        self.SubSectionDirs = Vector3.readn(file, self.NumVertexs)
        self.Boundaries = Vector3.readn(file, self.NumVertexs * 2)
        self.LBoundaries = Vector3.readn(file, self.NumVertexs)
        self.StopLightPos = Vector3.readn(file, 2)
        self.LaneWidths = read_unpack(file, '<5f')
        self.LaneLengths = read_unpack(file, '<10f')

        self.StopLightName = self.StopLightName.rstrip(b'\0').decode('ascii')

    def read(file):
        result = aiPath()
        result.load(file)
        return result

class aiIntersection:
    def load(self, file):
        self.ID, = read_unpack(file, '<H')
        self.Position = Vector3.read(file)

        num_sinks, = read_unpack(file, '<H')
        self.Sinks = read_unpack(file, '<{}I'.format(num_sinks))

        num_sources, = read_unpack(file, '<H')
        self.Sources = read_unpack(file, '<{}I'.format(num_sources))

        self.Paths = read_unpack(file, '<{}I'.format(num_sinks + num_sources))
        self.Directions = read_unpack(file, '<{}f'.format(num_sinks + num_sources))

    def read(file):
        result = aiIntersection()
        result.load(file)
        return result

class aiMap:
    def __init__(self):
        self.paths = []
        self.isects = []
        self.amb_roads = []
        self.ped_roads = []

    def load(self, file):
        num_isects, num_paths = read_unpack(file, '<2H')

        print('{} roads, {} isects'.format(num_paths, num_isects))

        for _ in range(num_paths):
            self.paths.append(aiPath.read(file))

        for _ in range(num_isects):
            self.isects.append(aiIntersection.read(file))

    def read(file):
        result = aiMap()
        result.load(file)
        return result

class MiniParser:
    def __init__(self, file):
        self.file = file
        self.indent = 0
        self.newline = False

    def print(self, data):
        if self.newline:
            self.file.write(' ' * (self.indent * 4))
            self.newline = False

        self.file.write(data)
        if data.endswith('\n'):
            self.newline = True

    def begin_class(self, name):
        self.print('{} :0 {{\n'.format(name))
        self.indent += 1

    def value(self, value):
        if isinstance(value, list):
            self.print('[\n')
            self.indent += 1
            for val in value:
                self.value(val)
                self.print('\n')
            self.indent -= 1
            self.print(']')
        elif isinstance(value, str):
            self.print('"{}"'.format(value.replace('\\', '\\\\').replace('"', '\\"')))
        elif isinstance(value, int):
            self.print(str(value))
        elif isinstance(value, float):
            self.print(repr(numpy.float32(value)))
        elif isinstance(value, Vector3):
            self.value(value.x)
            self.print(' ')
            self.value(value.y)
            self.print(' ')
            self.value(value.z)
        else:
            raise Exception('Invalid Value Type {}'.format(type(value)))

    def field(self, name, value):
        self.print(name)
        self.print(' ')
        self.value(value)
        self.print('\n')

    def end_class(self):
        self.indent -= 1
        self.print('}\n')

ai_map = aiMap()

game_dir = open('../../GameDirectory.txt', 'r').read().strip()

city_name = 'CHICAGO'
# city_name = 'RACETRACK2'

output_dir = r'{}dev/CITY/{}/'.format(game_dir, city_name)

with open(city_name + '.BAI', 'rb') as f:
    ai_map.load(f)

streets = []

for i, path in enumerate(ai_map.paths):
    # ID matches path index
    assert i == path.ID

    # A path should not be its own opposite.
    assert path.ID != path.OppositeID

    # A path should be properly linked with its opposite
    assert ai_map.paths[path.OppositeID].OppositeID == path.ID

    # No more than 1 sidewalk per road-side
    assert path.NumSidewalks in [0, 1]

    if path.ID < path.OppositeID:
        streets.append(('street_{}'.format(len(streets)), (path, ai_map.paths[path.OppositeID])))

assert len(streets) * 2 == len(ai_map.paths)

with open('{}{}.map'.format(output_dir, city_name), 'w') as f:
    parser = MiniParser(f)

    parser.begin_class('mmMapData')

    parser.field('NumStreets', len(streets))
    parser.field('Street', [ v[0] for v in streets ])

    parser.end_class()

for street_name, paths in streets:
    assert paths[0].NumVertexs == paths[1].NumVertexs
    assert paths[0].Divided == paths[1].Divided
    assert paths[0].Alley == paths[1].Alley
    assert paths[0].Normals == list(reversed(paths[1].Normals))

    with open('{}{}.road'.format(output_dir, street_name), 'w') as f:
        parser = MiniParser(f)

        parser.begin_class('mmRoadSect')

        parser.field('NumVertexs', paths[0].NumVertexs)

        parser.field('NumLanes[0]', paths[0].NumLanes)
        parser.field('NumLanes[1]', paths[1].NumLanes)

        parser.field('NumSidewalks[0]', paths[0].NumSidewalks * 2)
        parser.field('NumSidewalks[1]', paths[1].NumSidewalks * 2)

        all_vertexs = []

        for road in range(2):
            path = paths[road]
            split = path.NumLanes * path.NumVertexs
            all_vertexs += path.LaneVertices[0:split]

        if path.NumSidewalks:
            for road in range(2):
                path = paths[road]

                assert path.Boundaries[path.NumVertexs:] == list(reversed(paths[road ^ 1].LBoundaries))

                for i in range(path.NumVertexs):
                    a = path.LaneVertices[i + (path.NumLanes * path.NumVertexs)]
                    b = (path.Boundaries[i] + path.Boundaries[i + path.NumVertexs]) * 0.5
                    assert a.Dist2(b) < 0.00001

                all_vertexs += path.Boundaries

        expected_count = paths[0].NumVertexs * (paths[0].NumLanes + paths[1].NumLanes + (paths[0].NumSidewalks + paths[1].NumSidewalks) * 2)

        assert len(all_vertexs) == expected_count

        parser.field('TotalVertexs', len(all_vertexs))
        parser.field('Vertexs', all_vertexs)
        parser.field('Normals', paths[0].Normals)

        # Yes, these are "supposed" to be backwards
        parser.field('IntersectionType[0]', paths[1].IntersectionType)
        parser.field('IntersectionType[1]', paths[0].IntersectionType)
        parser.field('StopLightPos[0]', paths[1].StopLightPos[0])
        parser.field('StopLightPos[1]', paths[1].StopLightPos[1])
        parser.field('StopLightPos[2]', paths[0].StopLightPos[0])
        parser.field('StopLightPos[3]', paths[0].StopLightPos[1])

        parser.field('Blocked[0]', paths[0].Blocked)
        parser.field('Blocked[1]', paths[1].Blocked)

        parser.field('PedBlocked[0]', paths[0].PedBlocked)
        parser.field('PedBlocked[1]', paths[1].PedBlocked)

        # Yes, these are "supposed" to be backwards
        parser.field('StopLightName', [ paths[1].StopLightName, paths[0].StopLightName ])

        parser.field('Divided', paths[0].Divided)
        parser.field('Alley', paths[0].Alley)

        parser.end_class()
import ida_hexrays

R_fpstat = 0x36 # From intel.hpp
g_fps_reg = ida_hexrays.reg2mreg(R_fpstat)

def ProcessBlock(mblock):
    curr = mblock.head
    while curr:
        if curr.opcode == ida_hexrays.m_und and curr.d.t == ida_hexrays.mop_r and curr.d.r == g_fps_reg:
            mblock.make_nop(curr)
        curr = curr.next

class FPUHooks(ida_hexrays.Hexrays_Hooks):
    def microcode(self,mba):
        for i in range(mba.qty):
            ProcessBlock(mba.get_mblock(i))
        return ida_hexrays.MERR_OK

try:
    fpuhooks.unhook()
    del fpuhooks
except NameError as e:
    pass
finally:
    fpuhooks = FPUHooks()
    fpuhooks.hook()

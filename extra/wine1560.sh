#!/bin/bash

env WINEDLLOVERRIDES="dinput,ddraw=n,b" wine Open1560.exe $@

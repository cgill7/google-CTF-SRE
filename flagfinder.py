import angr
import claripy

# Addresses exctracted from assesmbly code
find_addr  = 0x101124 # success
avoid_addr = 0x10110d # failed
base_addr = 0x100000 # corresponding addresses Ghidra

FLAG_LEN = 15
STDIN_FD = 0

proj = angr.Project("./a.out", main_opts={'base_addr': base_addr}) 

flag_chars = [claripy.BVS('flag_%d' % i, 8) for i in range(FLAG_LEN)]
flag = claripy.Concat( *flag_chars + [claripy.BVV(b'\n')]) 

state = proj.factory.full_init_state(
        args=['./a.out'],
        add_options=angr.options.unicorn,
        stdin=flag,
)


for k in flag_chars:
    state.solver.add(k >= ord('!'))
    state.solver.add(k <= ord('~'))

simgr = proj.factory.simulation_manager(state)

simgr.explore(find=find_addr, avoid=avoid_addr)

if (len(simgr.found) > 0):
    for found in simgr.found:
        print(found.posix.dumps(STDIN_FD))

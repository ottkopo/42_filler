import subprocess
p1 = 0
p2 = 0
draw = 0
i = 0
while (i < 100):
    ret = subprocess.call(['../resources/filler_vm', '-p1', '../resources/players/carli.filler', '-p2', '../okoponen.filler', '-f', '../resources/maps/map00',	 '-q'])
    if ret == 1:
        p1 += 1
    if ret == 2:
        p2 += 1
    if ret == 0:
        draw += 1
    i += 1
print('p1 = ', p1)
print('p2 = ', p2)
print('draw = ', draw)

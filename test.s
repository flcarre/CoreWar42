.name "Test"
.comment "This is a test.."

#add r2,r3,r5
#zjmp %:live
sti r1,%:live, %1
live: live %1
ld %-64, r3
sti r3,%49,%2
ld %9,r2
sti r2,%38,%-3
ld %0 , r2
#add r2,r3,r5
#zjmp %100

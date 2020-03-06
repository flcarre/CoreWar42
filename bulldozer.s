.name "Test stronger"
.comment "This is a stronger test.."

live: live %1
ld %1,r2
sti r2, %0, %1


#sti r1,%:live, %1
#ld %-64, r3
#sti r3,%49,%2
#ld %9,r2
#sti r2,%38,%-3
#ld %0 , r2

.name "Test long long long long long name"
.comment "This is a test.."

trap:
	ld 		%0, r2
	zjmp	%:trap

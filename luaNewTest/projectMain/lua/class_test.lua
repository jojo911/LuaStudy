print('this is class_test lua file working')

function class_test()
	obj = CClassTest:new()
	local res = obj:sum(1,2)
	
	print('after sum the result is '..res)
end

class_test()
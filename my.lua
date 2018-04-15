package.cpath="?.so"

require("test")

-- l1, l2, l3, l4 = test.print(1, 2, 3, 4)

-- print(l1..l2..l3..l4)

table1 = {}

test.call(function (arg)
    print("in lua call, "..arg)
    f = io.open("util.C", "r")
    abc = f:read("*a")
    print(debug.traceback())
    f:close()
end)

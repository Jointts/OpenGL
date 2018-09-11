require 'test'

print("Lua main file loaded")

function reloadScript(path)
    print("Reloading script " .. path)

    package['loaded'][path] = nil
    require(path)
end
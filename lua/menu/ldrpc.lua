require("ldrpc")
--if LDRPC then PrintTable(LDRPC) else return print"shitty c++" end
if not LDRPC then return MsgC(Color(255, 0, 0), "Due to C++ (or VS2019) being complete trash, LDRPC is not working. :(\n") end
local state = "In Menu"

--     __     ____   _                               __ ____   ____   ______
--    / /    / __ \ (_)_____ _____ ____   _____ ____/ // __ \ / __ \ / ____/
--   / /    / / / // // ___// ___// __ \ / ___// __  // /_/ // /_/ // /     
--  / /___ / /_/ // /(__  )/ /__ / /_/ // /   / /_/ // _, _// ____// /___   
-- /_____//_____//_//____/ \___/ \____//_/    \__,_//_/ |_|/_/     \____/   

-- PASTING RNB FROM YOGPOD started
-- https://github.com/Yogpod/redandblackgmod/blob/master/lua/menu2/menu.lua
do
    local pasterworldtext = {
        [[    __     ____   _                               __ ____   ____   ______]],
        [[   / /    / __ \ (_)_____ _____ ____   _____ ____/ // __ \ / __ \ / ____/]],
        [[  / /    / / / // // ___// ___// __ \ / ___// __  // /_/ // /_/ // /     ]],
        [[ / /___ / /_/ // /(__  )/ /__ / /_/ // /   / /_/ // _, _// ____// /___   ]],
        [[/_____//_____//_//____/ \___/ \____//_/    \__,_//_/ |_|/_/     \____/   ]],
    }

    local longest = 0

    for _, v in pairs(pasterworldtext) do
        if v:len() > longest then
            longest = v:len()
        end
    end
    
    MsgN()
    
    for _, line in pairs(pasterworldtext) do
        for i = 1, line:len() do
            local hue = ((i - 1) / longest) * 360
            MsgC(HSVToColor(hue, 0.375, 1), line:sub(i, i))
        end
    
        MsgN()
    end
    
    MsgN()    
end
-- PASTING RNB FROM YOGPOD ended

--timer.Simple(2, function() LDRPC.Update("Lox eto ya") end)
LDRPC.Initialize() MsgC(Color(0, 255, 0), "LDRPC Initialized\n")
LDRPC.Update(state)
local function GetPastedLoadingStatusXD() -- https://github.com/Facepunch/garrysmod/blob/master/garrysmod/lua/menu/loading.lua#L141-L159
    local str = GetLoadStatus()
	if !str then return "" end

	str = string.Trim( str )
	str = string.Trim( str, "\n" )
	str = string.Trim( str, "\t" )

	str = string.gsub( str, ".bz2", "" )
	str = string.gsub( str, ".ztmp", "" )
	str = string.gsub( str, "\\", "/" )

    return str
end
timer.Create("LDRPC", 3, 0, function()
    local sstate
    if IsInGame() then sstate = "Playing on server" end
    if GetPastedLoadingStatusXD() ~= "" then sstate = "Loading: " .. GetPastedLoadingStatusXD() end
    if not sstate then sstate = "In Menu" end

    if state ~= sstate then state = sstate; LDRPC.Update(state) end
    --print(state, sstate)
end)
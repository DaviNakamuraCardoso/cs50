WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720

VIRTUAL_WIDTH = 432
VIRTUAL_HEIGHT = 243

push = require 'push'

require("class")

require 'util'
require 'Map'


function love.load()
    map = Map()

    love.graphics.setDefaultFilter('nearest', 'nearest')

    push:setupScreen(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, {
        resizable = false,
        fullscreen = false,
        vsync = true
    })
end

function love.update(dt)
    map:udpate(dt)
end


function love.draw()
    push:apply('start')
    love.graphics.clear(108 / 255, 140 / 255, 1, 1)
    love.graphics.translate(math.floor(-map.camX), math.floor(-map.camY))
    map:render()
    push:apply('end')
end

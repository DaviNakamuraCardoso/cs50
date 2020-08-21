--============================ Button Class =================================--

Button = Class{Block}

--============================================================================--


function Button:init(map, x, y, width, height, color)
    self.clicked = false
    self.timer = 0
    self.interval = 0.25
end

function Button:hover()
    mouseX = love.mouse.getX() * VIRTUAL_WIDTH / love.graphics.getWidth()
    mouseY = love.mouse.getY() * VIRTUAL_HEIGHT / love.graphics.getHeight()
    if self.x <= mouseX <= self.x + self.width and self.y <= mouseY <= self.y + self.height then
        return true
    end
end



function Button:update(dt)
    if self.timer > self.interval then
        self.timer = 0
        if self:hover() and love.mouse.isDown() then
            self.clicked = true

        else
            self.clicked = false
        end
    else
        self.timer = self.timer + dt
        self.clicked = false
    end
end

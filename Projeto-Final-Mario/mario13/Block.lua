--=============================== Block Class ================================--

Block = Class{}

--============================================================================--

function Block:init(map, x, y, width, height, color)
    self.map = map 
    self.x = x
    self.y = y
    self.width = width
    self.height = height
    self.color = color

end



function Block:render()
    love.graphics.setColor(self.color[1], self.color[2], self.color[3], self.color[4])
    love.graphics.rectangle('fill', self.map.camX + self.x, self.y + self.map.camY, self.width, self.height, 4, 4)


end

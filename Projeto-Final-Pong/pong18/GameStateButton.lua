--=========================== Game State Button =============================--
GameStateButton = Class(Button)
--============================================================================--

--=========================== Game State Button =============================--
function GameStateButton:construct(x, y, width, height, value)
    GameStateButton.super.construct(self, x, y, width, height)
    self.value = value 
end
--============================================================================--
function GameStateButton:update()
    if self:hover() then
        game_state = self.value
    end
end

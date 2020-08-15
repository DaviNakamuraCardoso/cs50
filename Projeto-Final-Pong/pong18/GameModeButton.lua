--============================= Game Mode Buttons ============================--
GameModeButton = Class(Button)
--============================================================================--

--=================================== Init ===================================--
function GameModeButton:construct(x, y, width, height, value)
    GameStateButton.super.construct(self, x, y, width, height)
    self.value = value



end
--============================================================================--
function GameModeButton:update()
    if self:hover() then
        game_mode = self.value
        game_state = 'start'  
    end
end

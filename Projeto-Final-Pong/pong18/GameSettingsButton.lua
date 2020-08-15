--=================================== Game Settings =========================--
GameSettingsButton = Class(Button)
--============================================================================--

--============================== Init ========================================--
function GameSettingsButton:construct(x, y, width, height, value)
    GameSettingsButton.super.construct(self, x, y, width, height)
    self.value = value
end



--============================================================================--
function GameSettingsButton:update()
    if self:hover() then
        return self.value
    else
        return 0
    end
end
















--============================================================================--

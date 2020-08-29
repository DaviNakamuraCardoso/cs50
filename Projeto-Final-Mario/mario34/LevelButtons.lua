--============================== Level Buttons ===============================--

LevelButtons = Class()
require 'commasep'
m = read('/home/davi/Documents/Code/Harvard-CS50/Projeto-Final-Mario/mario34/levels.txt')
--============================================================================--

function LevelButtons:construct(map, number, y, screenWidth, screenHeight, color)
    self.map = map
    self.number = number
    self.y = y
    self.color = color
    self.buttons = {}
    self.buttonsUnlocked = {}
    local buttonHeight = 2 * (screenHeight - y) / (3 * (self.number / 2 + 1)) + 1

    for j=-1, 1, 2 do
        for i=1, self.number/2 do
            local buttonY = self.y + buttonHeight / 2 + ((i - 1) * 1.5 * buttonHeight)
            self.buttons[i + (j+1) * self.number/4] = Button(self.map, screenWidth / 2 + j*80 - 40, buttonY, 80,   buttonHeight, self.color)
        end
    end
    for index=1, 10 do
        if m[index][2] == 1 then
            self.buttonsUnlocked[index] = true
        else
            self.buttonsUnlocked[index] = false
        end
    end

end


function LevelButtons:renderAll()
    for i=1, self.number do
        if not self.buttonsUnlocked[i] then
            self.buttons[i].color = colors['red']
            self.buttons[i]:render('LOCKED')
        else
            self.buttons[i]:render(tostring(i))
        end
    end

end


function LevelButtons:updateAll()
    for i=1, self.number do
        self.buttons[i]:update()
        if self.buttonsUnlocked[i] then
            m[i][2] = 1
            write('/home/davi/Documents/Code/Harvard-CS50/Projeto-Final-Mario/mario34/levels.txt', m)
            if self.buttons[i].clicked then
                gameState = 'play'
                map = Map(i)
            end

        
        end

    end
end

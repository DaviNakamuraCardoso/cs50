

function string:split(sSeparator, nMax, bRegexp)
    if sSeparator == '' then
        sSeparator = ','
    end

    if nMax and nMax < 1 then
        nMax = nil
    end

    local aRecord = {}

    if self:len() > 0 then
        local bPlain = not bRegexp
        nMax = nMax or -1

        local nField, nStart = 1, 1
        local nFirst,nLast = self:find(sSeparator, nStart, bPlain)
        while nFirst and nMax ~= 0 do
            aRecord[nField] = self:sub(nStart, nFirst-1)
            nField = nField+1
            nStart = nLast+1
            nFirst,nLast = self:find(sSeparator, nStart, bPlain)
            nMax = nMax-1
        end
        aRecord[nField] = self:sub(nStart)
    end

    return aRecord
end

---------------------------------------------------------------------
function read(path, sep, tonum, null)
    tonum = tonum or true
    sep = sep or ','
    null = null or ''
    csvFile = {}
    file = assert(io.open(path, "r"))
    for line in file:lines() do
        fields = line:split(sep)
        if tonum then -- convert numeric fields to numbers
            for i=1,#fields do
                local field = fields[i]
                if field == '' then
                    field = null
                end
                fields[i] = tonumber(field) or field
            end
        end
        table.insert(csvFile, fields)
    end
    file:close()
    return csvFile
end

---------------------------------------------------------------------
function write(path, data, sep)
    sep = sep or ','
    local file = assert(io.open(path, "w"))
    for i=1,#data do
        for j=1,#data[i] do
            if j>1 then file:write(sep) end
            file:write(data[i][j])
        end
        file:write('\n')
    end
    file:close()
end

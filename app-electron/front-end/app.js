const fs = require('fs');

include = function (name)
{
    document.write(fs.readFileSync('./' + name, 'utf8'));
};
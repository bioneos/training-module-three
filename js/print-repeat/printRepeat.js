const fs = require('fs');
const path = require('path');

if (process.argv.length <= 2)
{
  console.error('You must enter a file name.');
  process.exit(1);
}

const repeat = (times, callback) => {
  for (let i = 0; i < times; i++)
  {
    callback();
  }
};

let currentLine = '';
const print = () => {
  const text = currentLine.substring(currentLine.indexOf(' ') - 1);
  console.log(text);
  return print;
}

const filePath = path.join(__dirname, process.argv[2]);
fs.readFile(filePath, 'utf8', (err, data) => {
  if (err)
  {
    console.error(err);
    process.exit(2);
  }

  const lines = data.split('\n');
  lines.forEach(line => {
    currentLine = line;
    const times = Number(line.substring(0, line.indexOf(' ')));
    repeat(times, print());
  });

  process.exit(0);
});

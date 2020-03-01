const sqlite3 = require("sqlite3");
let db = new sqlite3.Database('./SSSIT.db', sqlite3.OPEN_READONLY, (err) => {
  if (err) {
    console.error(err.message);
    console.log('Connected to the database.');
  }
});

var x, y;

var http = require('http');

http.createServer(function (req, res) {
  res.writeHead(200, {'Content-Type': 'text/html'});
  res.write(`${x}, ${y}`);
  res.end();
}).listen(8080);



setInterval(() => {
    db.serialize(() => {
    console.log("Getting Values")
    
    db.get("SELECT * FROM coordinates WHERE id = 1", (err, row) => {
        if (err) {
        console.error(err.message);
        }
        console.log(row)
        values = {x: row.x, y: row.y}

        console.log("********************")
        console.log(values)
        console.log(`(${values.x}, ${values.y})`)
        x = values.x;
        y = values.y;
        console.log(`X: ${values.x}`)
        console.log(`Y: ${values.y}`)

    });
})
}, 2000) //Every 2 seconds


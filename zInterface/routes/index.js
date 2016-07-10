var express = require('express');
var router = express.Router();

// /* GET home page. */
// router.get('/', function(req, res, next) {
//   res.render('index', { title: 'Express' });
// });

router.get('/',function(req, res){
  //  res.status(404).send('Dafuq?');
  // res.set('Content-Type', 'application/json');
  // res.send(JSON.stringify({users: ["Will", "Laura"]}, null, 3));
  res.render('index', {
    title: 'My App!',
    age: 33
  });

});

module.exports = router;

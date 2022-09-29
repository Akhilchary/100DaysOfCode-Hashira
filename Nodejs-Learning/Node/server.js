// const http=require('http');

// const server=http.createServer((req,res)=>{
//     // console.log(req.url,req.method);
//     // console.log(res.statusCode);
//     res.setHeader('Content-Type','plain/html');
//     res.write("<p>heyyy bakas</p>");
//     res.end();
// });

// server.listen(3000,()=>{
//     console.log("server started");
// });


// const express=require('express');
// // const ejs=require('ejs');
// const app=express();

// //to set view engine for ejs
// app.set('view engine','ejs');


// // ,{root:__dirname}
// app.get('/',(req,res)=>{
//     res.render('index');
// });
// app.get('/about',(req,res)=>{
//     res.render('about');
// });
// app.use((req,res)=>{
//     res.status(404).render('404');
// });

// app.listen(3030,()=>{
//     console.log("running at port 3030");
// });

const express = require('express');

// express app
const app = express();

// listen for requests
app.listen(3000);

// register view engine
app.set('view engine', 'ejs');
// app.set('views', 'myviews');
//middleware to access static files
app.use(express.static('public'));
app.get('/', (req, res) => {
  const blogs = [
    {title: 'Yoshi finds eggs', snippet: 'Lorem ipsum dolor sit amet consectetur'},
    {title: 'Mario finds stars', snippet: 'Lorem ipsum dolor sit amet consectetur'},
    {title: 'How to defeat bowser', snippet: 'Lorem ipsum dolor sit amet consectetur'},
  ];
  res.render('index', { title: 'Home', blogs });
});

app.get('/about', (req, res) => {
  res.render('about', { title: 'About' });
});

app.get('/blogs/create', (req, res) => {
  res.render('create', { title: 'Create a new blog' });
});

// 404 page
app.use((req, res) => {
  res.status(404).render('404', { title: '404' });
});
const http=require('http');

const server=http.createServer((req,res)=>{
    // console.log(req.url,req.method);
    // console.log(res.statusCode);
    res.setHeader('Content-Type','plain/html');
    res.write("<p>heyyy bakas</p>");
    res.end();
});

server.listen(3000,()=>{
    console.log("server started");
});
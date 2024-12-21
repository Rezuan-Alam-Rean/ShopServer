const express = require('express');
const cors = require('cors');
const { MongoClient, ServerApiVersion } = require('mongodb');
require('dotenv').config();
const app = express();
const port = process.env.PORT || 4000;


// middleware
app.use(cors());
app.use(express.json());


//database connection

uri = `mongodb+srv://${process.env.DB_USER}:${process.env.DB_PASS}@cluster0.ndxdp2s.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0`;

const client = new MongoClient(uri, {
    serverApi: {
      version: ServerApiVersion.v1,
      strict: true,
      deprecationErrors: true,
    }
  });
  async function run() {
    try {
      // Connect the client to the server	(optional starting in v4.7)
      await client.connect();
      // Send a ping to confirm a successful connection
      await client.db("admin").command({ ping: 1 });
      console.log("Pinged your deployment. You successfully connected to MongoDB!");
    } finally {
      // Ensures that the client will close when you finish/error
    //   await client.close();
    }
  }
  run().catch(console.dir);


// routes

app.get('/', (req, res) => {
    res.send('server is running!')
})

app.listen(port, () => {
    console.log(` app listening on port  ${port}`)
})




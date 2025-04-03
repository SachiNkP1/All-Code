const express = require("express"); //es6 import express from "express";
const cors = require("cors");
const bodyParser = require("body-parser");
const { Pool } = require("pg");
require("dotenv").config();

const app = express();
const port = process.env.PORT || 5000;


// Middleware
app.use(cors());
app.use(bodyParser.json());

// PostgreSQL Connection
const pool = new Pool({
  user: process.env.DB_USER,
  host: process.env.DB_HOST,
  database: process.env.DB_NAME,
  password: process.env.DB_PASSWORD,
  port: process.env.DB_PORT,
});

// Routes

// 1. Get all books
app.get("/books", async (req, res) => {
  try {
    const result = await pool.query("SELECT * FROM books");
    res.json(result.rows);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// 2. Get a single book
app.get("/books/:id", async (req, res) => {
  try {
    const { id } = req.params;
    const result = await pool.query("SELECT * FROM books WHERE book_id = $1", [id]);
    res.json(result.rows[0]);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// 3. Add a new book
app.post("/books", async (req, res) => {
  try {
    const { title, author, published_year, genre, price } = req.body;
    const result = await pool.query(
      "INSERT INTO books (title, author, published_year, genre, price) VALUES ($1, $2, $3, $4, $5) RETURNING *",
      [title, author, published_year, genre, price]
    );
    res.json(result.rows[0]);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// 4. Update a book
app.put("/books/:id", async (req, res) => {
  try {
    const { id } = req.params;
    const { title, author, published_year, genre, price } = req.body;
    const result = await pool.query(
      "UPDATE books SET title=$1, author=$2, published_year=$3, genre=$4, price=$5 WHERE book_id=$6 RETURNING *",
      [title, author, published_year, genre, price, id]
    );
    res.json(result.rows[0]);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// 5. Delete a book
app.delete("/books/:id", async (req, res) => {
  try {
    const { id } = req.params;
    await pool.query("DELETE FROM books WHERE book_id=$1", [id]);
    res.json({ message: "Book deleted successfully" });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// Start Server
app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});

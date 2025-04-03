

export const addBook= async (req, res) => {
    try {
      const { title, author, published_year, genre, price } = req.body;
      const result = await pool.query(
        "INSERT INTO books (title, author, published_year, genre, price) VALUES ($1, $2, $3, $4, $5) RETURNING *",
        [title, author, published_year, genre, price]
      );
      res.json(result.rows[0]);
    } catch (err) {
      res.status(500).json({ error: err.message });
    }}


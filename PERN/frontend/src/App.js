import React from "react";
import BookList from "./BookList";
import AddBook from "./addBook";

function App() {
  return (
    <div>
      <h1>Bookstore App</h1>
      <AddBook />
      <BookList />
    </div>
  );
}

export default App;

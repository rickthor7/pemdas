// Komponen untuk menampilkan daftar buku
const BookList = Atomic.component("bookList", {
  template: `
    <div>
      <h2>Daftar Buku</h2>
      <button id="refreshBooks">Refresh</button>
      <ul id="bookList"></ul>
    </div>
  `,
  methods: {
    loadBooks: async () => {
      const response = await fetch("http://localhost:8080/books");
      const data = await response.json();
      const bookList = document.getElementById("bookList");

      bookList.innerHTML = ""; // Clear list
      data.books.forEach(book => {
        const li = document.createElement("li");
        li.textContent = `${book.title} by ${book.author}`;
        bookList.appendChild(li);
      });
    },
  },
  mounted() {
    this.loadBooks();

    // Refresh daftar buku
    document.getElementById("refreshBooks").addEventListener("click", this.loadBooks);
  },
});

// Komponen untuk menambahkan buku
const AddBook = Atomic.component("addBook", {
  template: `
    <div>
      <h2>Tambah Buku</h2>
      <form id="addBookForm">
        <label for="title">Judul:</label>
        <input type="text" id="title" name="title" required>
        <br>
        <label for="author">Penulis:</label>
        <input type="text" id="author" name="author" required>
        <br>
        <button type="submit">Tambah Buku</button>
      </form>
      <div id="addBookMessage"></div>
    </div>
  `,
  methods: {
    handleAddBook: async (event) => {
      event.preventDefault();

      const title = document.getElementById("title").value;
      const author = document.getElementById("author").value;

      const response = await fetch("http://localhost:8080/addBook", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ title, author }),
      });

      const message = await response.text();
      document.getElementById("addBookMessage").innerText = message;
    },
  },
  mounted() {
    // Tambahkan event listener ke form
    document.getElementById("addBookForm").addEventListener("submit", this.handleAddBook);
  },
});

// Mount komponen ke elemen dengan ID 'app'
Atomic.mount(BookList, "#app");
Atomic.mount(AddBook, "#app");

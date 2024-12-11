#include "crow_all.h"
#include <iostream>
#include <vector>
#include <string>

// Struktur untuk data buku
struct Book {
    int id;
    std::string title;
    std::string author;
};

// Data buku (sebagai database sementara)
std::vector<Book> books = {
    {1, "The C++ Programming Language", "Bjarne Stroustrup"},
    {2, "Clean Code", "Robert C. Martin"}
};

// Fungsi untuk mengubah data buku ke JSON
crow::json::wvalue bookToJson(const Book& book) {
    crow::json::wvalue result;
    result["id"] = book.id;
    result["title"] = book.title;
    result["author"] = book.author;
    return result;
}

int main() {
    crow::SimpleApp app;

    // Endpoint untuk daftar buku
    CROW_ROUTE(app, "/books").methods("GET"_method)([] {
        crow::json::wvalue response;
        for (const auto& book : books) {
            response["books"].push_back(bookToJson(book));
        }
        return response;
    });

    // Endpoint untuk menambahkan buku
    CROW_ROUTE(app, "/addBook").methods("POST"_method)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) {
            return crow::response(400, "Invalid JSON");
        }

        Book newBook;
        newBook.id = books.size() + 1;
        newBook.title = body["title"].s();
        newBook.author = body["author"].s();

        books.push_back(newBook);

        return crow::response(200, "Book added successfully!");
    });

    // Jalankan server pada port 8080
    app.port(8080).multithreaded().run();

    return 0;
}

// File: library_management_server.cpp

#include "crow.h" // Include Crow library
#include <vector>
#include <string>
#include <mutex>

using namespace std;

// Struktur data untuk menyimpan informasi buku
struct Book {
    string title;
    string author;
};

// Vektor untuk daftar buku (sebagai database sederhana)
vector<Book> books;
mutex booksMutex;

int main() {
    crow::SimpleApp app; // Membuat aplikasi Crow

    // Endpoint GET untuk mendapatkan daftar buku
    CROW_ROUTE(app, "/books").methods(crow::HTTPMethod::GET)([]() {
        lock_guard<mutex> lock(booksMutex);
        crow::json::wvalue response;
        response["books"] = crow::json::wvalue::list();

        for (const auto& book : books) {
            crow::json::wvalue bookJson;
            bookJson["title"] = book.title;
            bookJson["author"] = book.author;
            response["books"].push_back(bookJson);
        }
        return response;
    });

    // Endpoint POST untuk menambahkan buku
    CROW_ROUTE(app, "/addBook").methods(crow::HTTPMethod::POST)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("title") || !body.has("author")) {
            return crow::response(400, "Invalid input");
        }

        Book newBook = {body["title"].s(), body["author"].s()};
        {
            lock_guard<mutex> lock(booksMutex);
            books.push_back(newBook);
        }

        return crow::response(200, "Book added successfully");
    });

    // Menjalankan server pada port 18080
    app.port(18080).multithreaded().run();
}

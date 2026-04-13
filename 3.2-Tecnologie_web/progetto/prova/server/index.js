const express = require("express");
const app = express();

const PORT = 3000;
const HOST = "0.0.0.0";

const path = require("path");
const ROOT = path.join(__dirname, "..", "public");
app.use(express.static(ROOT));

/* ROUTES */

// Landing page
app.get("/", (req, res) => {
    res.sendFile(path.join(ROOT, "views", "landing.html"));
});

// Login
app.get("/login", (req, res) => {
    res.sendFile(path.join(ROOT, "views", "login.html"));
});
app.post("/login", (req, res) => {
    res.sendFile(path.join(ROOT, "views", "landing.html"));
});

// Register
app.get("/register", (req, res) => {
    res.sendFile(path.join(ROOT, "views", "register.html"));
});
app.post("/register", (req, res) => {
    res.sendFile(path.join(ROOT, "views", "landing.html"));
});

// Logout
app.get("/logout", (req, res) => {
    res.sendFile(path.join(ROOT, "views", "logout.html"));
});
app.post("/logout", (req, res) => {
    res.sendFile(path.join(ROOT, "views", "landing.html"));
});


/* START SERVER */
app.listen(PORT, HOST, () => {
    console.log(`Server running on http://localhost:${PORT}...`);
});
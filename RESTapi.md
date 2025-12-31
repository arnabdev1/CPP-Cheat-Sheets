# 📚 Ultimate REST API Guide & Interview Notes

A comprehensive guide to understanding, building, and mastering RESTful APIs. This repository serves as a study aid for full-stack developer interviews, covering theory, implementation (Node.js & Flask), and common interview questions.

---

## 📖 Table of Contents
1. [What is a REST API?](#what-is-a-rest-api)
2. [The 6 Guiding Constraints](#the-6-guiding-constraints)
3. [HTTP Methods & Idempotency](#http-methods--idempotency)
4. [HTTP Status Codes (Must Know)](#http-status-codes-must-know)
5. [Anatomy of a Request](#anatomy-of-a-request)
6. [Implementation: Node.js & Express](#implementation-nodejs--express)
7. [Implementation: Python & Flask](#implementation-python--flask)
8. [Best Practices (Versioning, Pagination, Security)](#best-practices)
9. [🔥 Top Interview Questions & Answers](#-top-interview-questions--answers)

---

## What is a REST API?

**REST** stands for **Re**presentational **S**tate **T**ransfer. It is not a protocol (like HTTP) or a library, but an **architectural style** for designing networked applications[cite: 23].

* **Core Concept:** Resources (data entities like Users, Products, Orders) are treated as objects accessible via a specific URI (Uniform Resource Identifier).
* **Communication:** Data is usually exchanged in **JSON** (JavaScript Object Notation) format, though XML is also possible[cite: 25].
* **Goal:** To allow different software systems to communicate over the internet regardless of their underlying language or platform[cite: 23].

---

## The 6 Guiding Constraints

To be truly "RESTful," an API must adhere to these architectural constraints:

### 1. Client-Server Architecture
The user interface (Client) is completely separate from the data storage and logic (Server)[cite: 54].
* **Benefit:** Portability of the UI and scalability of the server. They evolve independently.

### 2. Statelessness
**Crucial for Interviews:** The server **never** stores information about the client's session[cite: 28, 56].
* Every single request must contain **all** the information necessary to process it (e.g., Auth tokens, filters)[cite: 28].
* **Benefit:** Reliability and Scalability. The server doesn't need to remember "who asked for this 5 minutes ago."

### 3. Cacheable
Responses must define themselves as cacheable or non-cacheable[cite: 58].
* If a response is cacheable, the client can reuse that data for equivalent requests later.
* **Benefit:** Reduces server load and improves client performance[cite: 58].

### 4. Uniform Interface
This is the most distinguishing feature of REST. It simplifies and decouples the architecture[cite: 52].
* **Resource Identification:** Resources are named in requests (e.g., `/api/users/1`).
* **Self-Descriptive Messages:** The message contains enough info to describe how to process it (e.g., `Content-Type: application/json`).
* **HATEOAS:** (Hypermedia As The Engine Of Application State) - Responses should contain links to other related resources (like a website menu).

### 5. Layered System
The client cannot tell if it is connected directly to the end server or an intermediary (like a load balancer or proxy)[cite: 60].
* **Benefit:** Improves scalability and security[cite: 62].

### 6. Code on Demand (Optional)
Servers can temporarily extend or customize client functionality by transferring executable code (e.g., Java applets or client-side JavaScript)[cite: 63].

---

## HTTP Methods & Idempotency

Understanding **Idempotency** is a key interview differentiator. An operation is **idempotent** if making the same request multiple times produces the same result as making it once.

| Method | Description | CRUD Operation | Safe? | Idempotent? |
| :--- | :--- | :--- | :--- | :--- |
| **GET** | Retrieve data. Should have no side effects. | Read | Yes | **Yes** |
| **POST** | Submit data to create a resource. | Create | No | **No** |
| **PUT** | Update/Replace a resource entirely. | Update (Full) | No | **Yes** |
| **PATCH** | Update a resource partially. | Update (Partial)| No | No* |
| **DELETE** | Remove a resource. | Delete | No | **Yes** |
| **HEAD** | Same as GET but returns headers only (no body). | Read | Yes | **Yes** |

*> **Note on PATCH:** PATCH is theoretically non-idempotent, though most APIs implement it idempotently.*

---

## HTTP Status Codes (Must Know)

Don't just say "It returns an error." Be specific.

### 2xx: Success
* **200 OK:** Standard response for successful HTTP requests.
* **201 Created:** The request has been fulfilled and a new resource has been created (standard for POST)[cite: 198].
* **204 No Content:** The request succeeded, but there is no content to send (standard for DELETE).

### 3xx: Redirection
* **301 Moved Permanently:** This and all future requests should be directed to the given URI.
* **304 Not Modified:** Tells the client that the response has not been modified so the client can continue to use the same cached version.

### 4xx: Client Errors
* **400 Bad Request:** The server cannot process the request due to a client error (e.g., malformed syntax).
* **401 Unauthorized:** Authentication is required and has failed or has not been provided.
* **403 Forbidden:** The client has valid credentials but not enough privileges to perform the action.
* **404 Not Found:** The requested resource could not be found.

### 5xx: Server Errors
* **500 Internal Server Error:** A generic error message when the server encounters an unexpected condition.
* **502 Bad Gateway:** The server was acting as a gateway or proxy and received an invalid response from the upstream server.

---

## Anatomy of a Request

When making a request (e.g., via Postman or Fetch), it consists of:

1.  **Endpoint (URL):** `https://api.example.com/users/123`
2.  **Method:** GET, POST, etc.
3.  **Headers:** Meta-data (Auth tokens, Content-Type).
    * `Authorization: Bearer <token>`
    * `Content-Type: application/json`
4.  **Body (Data):** The JSON payload (used in POST/PUT/PATCH).
    * `{ "name": "John", "age": 30 }`[cite: 25].

---

## Implementation: Node.js & Express

This is a complete CRUD implementation. Unlike basic tutorials, this includes data persistence (in-memory) and error handling.

### 1. Setup
```bash
mkdir my-api
cd my-api
npm init -y
npm install express
# Optional: npm install nodemon --save-dev (for auto-restart)

```

### 2. `server.js` Code

```javascript
const express = require('express');
const app = express();
const PORT = 3000;

// Middleware to parse JSON bodies [cite: 119]
app.use(express.json());

// Mock Database (In-Memory)
let items = [
    { id: 1, name: "Laptop", price: 999 },
    { id: 2, name: "Mouse", price: 25 }
];

// ----------------------------------------------------
// 1. GET - Retrieve all items [cite: 138]
// ----------------------------------------------------
app.get('/api/items', (req, res) => {
    res.status(200).json({
        success: true,
        count: items.length,
        data: items
    });
});

// ----------------------------------------------------
// 2. GET (by ID) - Retrieve single item
// ----------------------------------------------------
app.get('/api/items/:id', (req, res) => {
    // req.params.id fetches the URL parameter [cite: 163]
    const item = items.find(i => i.id === parseInt(req.params.id));

    if (!item) {
        return res.status(404).json({ success: false, message: "Item not found" });
    }

    res.status(200).json({ success: true, data: item });
});

// ----------------------------------------------------
// 3. POST - Create new item [cite: 147]
// ----------------------------------------------------
app.post('/api/items', (req, res) => {
    // req.body contains the data sent by client [cite: 153]
    const { name, price } = req.body;

    if (!name || !price) {
        return res.status(400).json({ success: false, message: "Please provide name and price" });
    }

    const newItem = {
        id: items.length + 1,
        name: name,
        price: price
    };

    items.push(newItem);

    // 201 status for creation [cite: 198]
    res.status(201).json({ success: true, data: newItem });
});

// ----------------------------------------------------
// 4. PUT - Update item fully [cite: 158]
// ----------------------------------------------------
app.put('/api/items/:id', (req, res) => {
    const id = parseInt(req.params.id);
    const itemIndex = items.findIndex(i => i.id === id);

    if (itemIndex === -1) {
        return res.status(404).json({ success: false, message: "Item not found" });
    }

    // Update the item
    items[itemIndex] = {
        id: id,
        name: req.body.name, // In PUT, we usually expect the full object
        price: req.body.price
    };

    res.status(200).json({ success: true, data: items[itemIndex] });
});

// ----------------------------------------------------
// 5. DELETE - Remove item [cite: 168]
// ----------------------------------------------------
app.delete('/api/items/:id', (req, res) => {
    const id = parseInt(req.params.id);
    const itemIndex = items.findIndex(i => i.id === id); // [cite: 176]

    if (itemIndex === -1) {
        return res.status(404).json({ success: false, message: "Item not found" });
    }

    // Remove from array
    items.splice(itemIndex, 1);

    res.status(200).json({ success: true, message: `Item ${id} deleted` });
});

// Start Server
app.listen(PORT, () => console.log(`Server running on port ${PORT}`));

```

---

## Implementation: Python & Flask

For Python roles, Flask is the most common equivalent to Express for simple REST APIs.

### 1. Setup

```bash
pip install flask

```

### 2. `app.py` Code

```python
from flask import Flask, jsonify, request

app = Flask(__name__)

# Mock Database
items = [
    {"id": 1, "name": "Laptop", "price": 999},
    {"id": 2, "name": "Mouse", "price": 25}
]

# ----------------------------------------------------
# 1. GET - Retrieve all items
# ----------------------------------------------------
@app.route('/api/items', methods=['GET'])
def get_items():
    return jsonify({"success": True, "count": len(items), "data": items}), 200

# ----------------------------------------------------
# 2. GET (by ID) - Retrieve single item
# ----------------------------------------------------
@app.route('/api/items/<int:item_id>', methods=['GET'])
def get_item(item_id):
    # Search for item
    item = next((item for item in items if item["id"] == item_id), None)
    
    if item:
        return jsonify({"success": True, "data": item}), 200
    else:
        return jsonify({"success": False, "message": "Item not found"}), 404

# ----------------------------------------------------
# 3. POST - Create new item
# ----------------------------------------------------
@app.route('/api/items', methods=['POST'])
def create_item():
    data = request.get_json()
    
    if not data or 'name' not in data or 'price' not in data:
        return jsonify({"success": False, "message": "Missing name or price"}), 400
        
    new_item = {
        "id": len(items) + 1,
        "name": data['name'],
        "price": data['price']
    }
    
    items.append(new_item)
    return jsonify({"success": True, "data": new_item}), 201

# ----------------------------------------------------
# 4. PUT - Update item
# ----------------------------------------------------
@app.route('/api/items/<int:item_id>', methods=['PUT'])
def update_item(item_id):
    item = next((item for item in items if item["id"] == item_id), None)
    
    if not item:
        return jsonify({"success": False, "message": "Item not found"}), 404
        
    data = request.get_json()
    item.update(data) # Updates the dictionary in place
    
    return jsonify({"success": True, "data": item}), 200

# ----------------------------------------------------
# 5. DELETE - Remove item
# ----------------------------------------------------
@app.route('/api/items/<int:item_id>', methods=['DELETE'])
def delete_item(item_id):
    global items
    # Filter out the item to be deleted
    items = [item for item in items if item["id"] != item_id]
    
    return jsonify({"success": True, "message": f"Item {item_id} deleted"}), 200

if __name__ == '__main__':
    app.run(debug=True, port=5000)

```

---

## Best Practices

To pass a senior or mid-level interview, mention these concepts:

1. **Versioning:** Always version your API. This prevents breaking changes for existing users.


* Example: `https://api.example.com/v1/users`


2. **Resource Naming:** Use **plural nouns**, not verbs.
* ❌ Bad: `/api/getUsers`, `/api/createUser`
* ✅ Good: `GET /api/users`, `POST /api/users`


3. **Pagination:** Essential for performance. Don't return 1,000,000 records at once.
* Example: `GET /api/users?page=2&limit=50`


4. **Security:**
* Use **HTTPS** (SSL/TLS).
* **Rate Limiting:** Prevent DDoS attacks by limiting requests per IP.
* **CORS:** (Cross-Origin Resource Sharing) Configure who can call your API.



---

## 🔥 Top Interview Questions & Answers

### Q1: What is the difference between REST and SOAP?

* **REST:** Architectural style, lightweight, uses JSON (mostly), stateless, flexible, uses standard HTTP verbs.
* **SOAP:** Protocol, heavy/strict, uses XML only, stateful or stateless, highly secure (WS-Security), strictly typed.

### Q2: What is the difference between PUT and PATCH?

* **PUT** is for a **full update**. You send the *entire* resource representation. If a field is missing, it might be nulled out. PUT is idempotent.
* **PATCH** is for a **partial update**. You only send the fields you want to change. It is generally more bandwidth-efficient.

### Q3: Explain "Statelessness" in REST.

It means the server does not hold any data (state) about the client's session between requests. The client must send the token/credentials with *every single* request. This allows the server to scale easily because any server instance can handle any request.

### Q4: How do you secure a REST API?

* Use **HTTPS** to encrypt data in transit.
* Use **Authentication** (e.g., OAuth2, JWT) to verify user identity.
* Use **Authorization** (Scopes/Roles) to verify permissions.
* Input Validation (Sanitize data to prevent SQL Injection/XSS).
* Rate Limiting.

### Q5: What is Idempotency and which methods are idempotent?

Idempotency means making the same request multiple times yields the same result on the server side.

* **Idempotent:** GET, PUT, DELETE, HEAD, OPTIONS.
* **Non-Idempotent:** POST (calling it 3 times creates 3 different records).

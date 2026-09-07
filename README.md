# 🎬 MOVIE TICKET BOOKING SYSTEM (LLD & OOP)

[![C++ Version](https://shields.io)](https://isocpp.org)
[![LLD Project](https://shields.io)]()
[![SOLID Principles](https://shields.io)]()

A modular, menu-driven **C++ console application** that models an end-to-end ticketing workspace for a single cinema (like PVR or INOX). Engineered to satisfy rigid Object-Oriented Programming (OOP) benchmarks, Low-Level Design (LLD) parameters, and clean code criteria without relying on standard `.h` header configurations.

---

## 🧭 PROJECT OVERVIEW & FEATURES

The application simulates real-world theatre operations directly inside the command line terminal through 8 core features:

*   **F1: Movie Directory** 🍿 — Lists all movies currently playing in the theatre.
*   **F2: Show Scheduling** ⏰ — Maps movies out by their respective screen locations and start times.
*   **F3: Visual Matrix** 🪑 — Renders real-time grid layouts showing `[ ] AVAILABLE` and `[X] BOOKED` seat statuses.
*   **F4: Multi-Seat Booking** 🎟️ — Allows booking multiple seats concurrently; safely rejects the whole order if any seat is taken.
*   **F5: Tiered Costing** 💰 — Automatically calculates prices by seat tier: `SILVER (₹150)`, `GOLD (₹250)`, and `PLATINUM (₹400)`.
*   **F6: Fail-Safe Gateways** 💳 — Simulates checkouts via UPI, Card, or Cash. Rejects seat confirmation immediately if the payment fails.
*   **F7: Automated Invoicing** 📄 — Prints structured tax slips displaying unique Booking IDs, screen details, seat choices, and totals.
*   **F8: Dynamic Cancellation** 🔄 — Instantly cancels active tickets and updates the corresponding seats back to the available pool.

---

## 📂 DECOUPLED ARCHITECTURE MATRIX

Adhering to strict modularity constraints, this project utilizes a **one-class-per-file paradigm completely free of `.h` header modules**:

```bash
├── 01_Movie.cpp            # Base data models (Title, language, duration)
├── 02_Seat.cpp             # Physical properties tracking seat numbers and tiers
├── 03_Screen.cpp           # Auditorium wrapper managing layout sizes and raw seats
├── 04_Cinema.cpp           # Main theater shell containing structural layout groups
├── 05_Show.cpp             # Links a Movie to a Screen at a specific time with its own seats
├── 06_ShowSeat.cpp         # Dynamic seat allocations separate from static physical chairs
├── 07_Customer.cpp         # Basic profile data structure (Name, Contact information)
├── 08_Booking.cpp          # Invoice models holding unique transaction IDs and metrics
├── 09_Payment.cpp          # Pure virtual base contract tracking generic transactions
├── 10_PaymentTypes.cpp     # Polymorphic implementation blocks for UPI, Card, and Cash
├── 11_PriceCalculator.cpp  # Isolated domain pricing logic engine
├── 12_TicketPrinter.cpp    # Terminal stream formatting layout utility
├── 13_BookingService.cpp   # Main orchestrator handling operational loops and flows
└── main.cpp                # App bootstrapper, menu loops, and user input validation
```

---

## 📐 LOW-LEVEL DESIGN INSIGHTS

### 🤝 Lifetime-Invariant Relationships
Every object relation inside the engine relies heavily on structural lifetime behavior tests:
*   **Cinema ──◆ Screen** *(Composition)*: If the theater structure is torn down, all physical auditoriums cease to exist.
*   **Screen ──◆ Seat** *(Composition)*: Physical theater rows depend exclusively on the layout of their containing hall.
*   **Show ──◇ Movie** *(Aggregation)*: A show borrows a film profile. Deleting a scheduled time block does not destroy the movie entry.
*   **Show ──◆ ShowSeat** *(Composition)*: Custom `AVAILABLE`/`BOOKED` tracking states exist only for the lifespan of that specific showtime.

### 🛠️ Applied SOLID Blueprints
*   **Single Responsibility (SRP):** Clean separation between transaction storage (`Booking`) and UI data presentation formatting (`TicketPrinter`).
*   **Open/Closed Principle (OCP):** Introducing new transactional variations (e.g., NetBanking) only requires creating new standalone subclasses without modifying core orchestrator paths.
*   **Liskov Substitution (LSP):** Concrete options (`UpiPayment`, `CardPayment`) integrate cleanly via uniform polymorphic pointers (`Payment*`) with no extra configurations.

---

## 📈 ASSIGNMENT DEVELOPMENT CHECKLIST

### 📋 Phase Progress
- [ ] **Step A:** Functional & Non-Functional Precise Analysis Specification
- [ ] **Step B:** Class Attribute & Method Noun-Verb Parsing
- [ ] **Step C:** Structural Modifiers & Invariant Responsibilities Definitions
- [ ] **Step D:** Structural Relationship Matrix & Justification Map
- [ ] **Step E:** Formal UML Class Diagram Design
- [ ] **Step F:** Dynamic Show-to-Print Sequence Diagram
- [ ] **Step G:** Working C++ Code Modular Assembly

### 🧪 Edge Case Verification
- [ ] Overlapping seat selections are blocked safely with no partial state updates.
- [ ] Failed checkouts drop transactions safely and release held seat vectors.
- [ ] Cancellation routines perfectly clear target arrays back to `AVAILABLE` status.
- [ ] Invalid selections and inputs are handled cleanly with zero memory leaks or app crashes.

---

## 💻 BUILD & COMPILATION INSTRUCTIONS

To build and run this application locally, pull the multi-file architecture directly into any standard GCC/G++ terminal workspace:

```bash
# 1. Clone your project workspace
git clone https://github.com
cd YOUR_REPOSITORY

# 2. Compile all decoupled files collectively into a single target binary executable
g++ -std=c++17 main.cpp 01_Movie.cpp 02_Seat.cpp 03_Screen.cpp 04_Cinema.cpp 05_Show.cpp 06_ShowSeat.cpp 07_Customer.cpp 08_Booking.cpp 09_Payment.cpp 10_PaymentTypes.cpp 11_PriceCalculator.cpp 12_TicketPrinter.cpp 13_BookingService.cpp -o MovieBookingApp

# 3. Launch the terminal runtime executable
./MovieBookingApp
```

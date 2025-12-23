# Lightweight Blockchain-Based Framework for Secure IoT Communication

**A simulation of a secure, energy-efficient blockchain architecture for resource-constrained IoT networks using OMNeT++.**

![OMNeT++](https://img.shields.io/badge/Simulator-OMNeT%2B%2B-blue) ![Language](https://img.shields.io/badge/Language-C%2B%2B%20%7C%20NED-orange) ![Status](https://img.shields.io/badge/Status-Research%20Prototype-green)

---

## 📋 Project Overview
This project addresses the "Security-Energy Paradox" in the Internet of Things (IoT). Standard blockchain protocols (like Bitcoin) are too heavy for battery-powered sensors. 

We propose a **Split-Architecture Framework**:
1.  **Sensor Layer (Users):** Low-power devices that perform simple hashing and data transmission.
2.  **Edge Layer (Miners):** Powerful gateways that handle heavy consensus and verification tasks.

**Key Features:**
* **Decentralized Topology:** Star-Ring hybrid network.
* **Lightweight Cryptography:** Custom string-based hashing for integrity verification.
* **Attack Simulation:** Includes a "Man-in-the-Middle" attack scenario with 100% detection rate.
* **Visual Dashboard:** Real-time color-coded visualization of node states (Green = Mining, Red = Attack).

---

## ⚙️ Prerequisites & Requirements

Before running the simulation, ensure you have the following installed:

| Component | Requirement | Notes |
| :--- | :--- | :--- |
| **OS** | Windows 10/11, Linux, or macOS | Tested primarily on Windows 11 |
| **Simulator** | **OMNeT++ 6.0 or higher** | **Recommended: v6.2.0** |
| **Compiler** | MinGW (Windows) or GCC (Linux) | Bundled with OMNeT++ on Windows |
| **Framework** | INET Framework (Optional) | Not strictly required for the core logic, but good for extensions |

> **Note:** This project relies on the standard OMNeT++ kernel (`cSimpleModule`) and does not require external blockchain libraries.

---

## 🚀 How to Run the Simulation

### Step 1: Clone the Repository
Open your terminal or command prompt and run:
```bash
git clone [https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git](https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git)
cd YOUR_REPO_NAME
make
./out/clang-release/blockchainSimulation.exe

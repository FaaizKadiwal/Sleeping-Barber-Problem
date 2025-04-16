# 💤 Sleeping Barber Problem (Linux Kernel System Call)

This project implements the classic **Sleeping Barber Problem** using **semaphores** as a system call inside the **Linux kernel**. It addresses key issues in **process synchronization**, such as **deadlock prevention** and **resource starvation**, making it an excellent example of practical operating system-level thread management.

---

## 📌 Table of Contents

- [Introduction](#introduction)
- [Project Highlights](#project-highlights)
- [Technology Stack](#technology-stack)
- [System Architecture](#system-architecture)
- [Source Code Breakdown](#source-code-breakdown)
- [Installation & Usage](#installation--usage)
- [Output Example](#output-example)
- [Contributors](#contributors)
- [References](#references)

---

## 📖 Introduction

This kernel module simulates a barber shop with limited waiting chairs and multiple customer threads. It demonstrates kernel-level synchronization using Linux **semaphores**, and thread creation via `kthread_create`. The system call `sleepingbarber` coordinates the barber and customer interaction, where:

- The barber sleeps when no customers are present.
- Customers either wait or leave if the waiting room is full.
- The barber wakes up and services customers one-by-one.

---

## ✨ Project Highlights

- Implemented as a **custom system call** using `SYSCALL_DEFINE0`.
- Utilizes **kernel semaphores** for synchronization.
- Demonstrates **thread creation and stopping** using `kthread_create()` and `kthread_stop()`.
- Configured and compiled into a **custom Linux kernel module**.
- Handles edge conditions like customer overflow and resource contention.

---

## 🧰 Technology Stack

- **Platform:** Ubuntu 20.04
- **Language:** C (Kernel-Level)
- **Kernel Threads:** `kthread_create`, `kthread_stop`
- **Synchronization:** `sema_init`, `down`, `up` (Linux semaphores)
- **System Call Declaration:** `SYSCALL_DEFINE0`
- **Debugging Tool:** `dmesg` (for kernel log inspection)

---

## 🏗 System Architecture

- **Semaphores Used:**
  - `waiting` – Number of chairs in the waiting room.
  - `barber_Chair` – Indicates if the barber chair is free.
  - `barber_sleeping` – Used to wake the sleeping barber.
  - `barber_seatbelt` – Controls customer release after service.

- **Threads:**
  - One barber thread
  - Multiple customer threads (customizable)

---

## 🧩 Source Code Breakdown

### `sleepingbarber.c`

- Defines and initializes kernel semaphores.
- Spawns barber and customer threads.
- Encapsulates logic for customer arrival, waiting, and servicing.
- Utilizes `printk` for kernel-level logging.
- Uses `msleep()` to simulate haircut duration.

---

## ⚙️ Installation & Usage

### 1. Configure Kernel to Support Custom System Call

Follow [this guide](https://0xax.gitbooks.io/linux-insides/content/SyncPrim/linux-sync-3.html) or the documentation for steps.

### 2. Build the Kernel Module

make

### 3. Load Module

sudo insmod sleepingbarber.ko

### 4. Trigger the system call

sudo dmesg

---

## 🖨 Output Example

Number of Chairs are 3 and Number of customers are 5
Sleeping Barber Problem Implementation Using Semaphores:
Customer 1 left to get a haircut.
Customer 1 reached the barber shop.
Customer 1 entered the waiting room.
Customer 1 asked the sleeping barber for a haircut.
The barber is sleeping
The barber is busy servicing the customer
The barber has finished servicing the customer.
Customer 1 left the barber shop.
...
The Barber's Job Is All Done For The Day!

---

## 🛠 This project was built as part of our Operating Systems course to demonstrate kernel-level synchronization and system call extension.

### 👥 National University of Computer and Emerging Sciences


# FPGA-Based Image Processing Pipeline Simulator (C++)

## Project Overview
This project is a **C++ simulation of an FPGA-style image processing pipeline**, developed as part of the **IC Design Special Course (Weeks 1–4)**.  
The goal is to model how hardware image-processing pipelines work in FPGA/SoC systems using **software abstractions**.

The pipeline processes a **real PPM (P6 binary) image** through multiple stages and generates intermediate and final outputs.

---

## Project Objectives
- Simulate a hardware-oriented image processing pipeline in C++
- Use **modular design** with multiple source and header files
- Apply **OOP concepts** such as inheritance and polymorphism
- Practice **dynamic memory management**
- Automate builds using a **Makefile**
- Understand compilation and linking stages
- Deploy the project using **GitHub**

---

## 🧠 Concepts Used
- C++ classes, structs, and pointers
- Dynamic memory allocation (`new` / `delete`)
- Inheritance and polymorphism (Filter base class)
- Separate compilation and linking
- Makefile-based build automation
- Binary image file handling (PPM – P6 format)
- Hardware-style pipeline modeling

---

## Pipeline Stages
1. **Frame Reader**  
   Reads a real PPM (P6) image into a dynamically allocated buffer.

2. **Color Converter**  
   Converts RGB image to grayscale.

3. **Blur Filter**  
   Applies a 3×3 average smoothing filter.

4. **Edge Detection**  
   Uses Sobel operator for edge detection.

5. **Output Writer**  
   Saves intermediate and final results as PPM images.

---

## 📂 Project Structure

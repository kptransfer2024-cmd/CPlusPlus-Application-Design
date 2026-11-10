# C++ & AI

## 1. Research: ONNX Runtime

I researched **ONNX Runtime**, a tool that runs trained AI models using C++ and other languages. It uses CPU or GPU resources to make predictions efficiently.

"ONNX Runtime is a cross-platform, high-performance machine learning inference and training accelerator developed by Microsoft. It is designed to speed up execution and lower compute costs for models built across diverse frameworks"

C++ helps with fast computation, memory management, and running AI models inside applications. This makes it useful, lower computing costs, and more time efficient for AI systems that need to process large amounts of data.

**Sources:**

- [ONNX Runtime Documentation](https://onnxruntime.ai/docs/)

- [ONNX Runtime C/C++ API](https://onnxruntime.ai/docs/api/c/index.html)

## 2. My Application: Inventory Forecasting

In Module 9, I built a simple AI Inventory Assistant that answers questions and identifies low-stock devices.

For this Module, I created a separate C++ program that predicts next week's borrowing demand using four weeks of simulated data (using Ordinary Least Squares (OLS) linear regression, then round up for the prediction). 

It compares predicted demand with available stock and suggests which devices may need restocking.

This is a basic statistical (OLS) prediction, not a trained AI model. I used simulated data because my current application doesn't save borrowing history.

## 3. Future Improvements

If my inventory system becomes larger, I could track actual borrowing history and use machine learning (or other algorithms) to train an AI model to predict future demand.

I could then apply **ONNX Runtime's C++ API** to run the model directly in my application. This would enhance the inventory assistant by helping users plan ahead regarding stock levels.
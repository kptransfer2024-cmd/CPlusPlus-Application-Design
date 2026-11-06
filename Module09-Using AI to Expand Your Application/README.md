## Overview

For Module 9, I added an AI Inventory Assistant prototype to my Midterm Lab Inventory Management System. It reuses my existing C++ classes (#include from /Midterm folder) and adds a new feature (Mock AI Assistant / a chatbox).


### What Does It Do?

Users can ask simple questions about the inventory, such as:

"Which devices need restocking?"

"Summarize the inventory."

"Which device is the most expensive?"

The assistant uses device names, prices, and stock quantities stored in devices.txt (our long-term database) to generate responses.

### How Does It Work?

I added a new menu option, 10. AI Inventory Assistant, and created AIAssistant.h and AIAssistant.cpp.

The program reads inventory data from devices.txt, checks the data, and generates a response based on the user's question.

Currently, it uses rule-based (deterministic) logic instead of a real AI API, since it's a mock verison. In the future, I could connect an AI model setting an API to understand and answer more complex questions.
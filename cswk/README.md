# Project Title: COMP2811 UI Final Project Coursework

- **Team Members**:
    - Shaikha Mohamed Al Slais - Student ID: 201659913
    - Juri Hamed Al Subhi - Student ID: 201778857
    - Kito Magu - Student ID: 

- **Project Overview**:
    This application, built using Qt, is designed to monitor and track UK and EU water quality data. It provides data visualization through charts, making it easier to understand trends and patterns. Users can filter specific pollutants and evaluate their safety levels, as well as filter data by location to assess compliance with regulations.

- **Setup Instructions**:
    1. **Extract the Starter Code**: 
        - Unzip the provided starter code package to a working directory.
    2. **Build the Project**:
        - Create a `build` directory and run `cmake`:
        ```bash
        mkdir build && cd build
        cmake ..
        ```
        - Compile the project:
        ```bash
        make
        ```
        - Run the application:
      ```bash
      ./[application-executable-name]
      ```

- **File Structure**:
    - This folder consists of 2 files, 
        - the data file which has 5 CSV files from 2020-2024 in Yorkshire. Any of these files can be chosen from to load. 
        - the translation file has the ts and qm of the spanish, en gb and en languages and their qm in order for the language  to be changed depending on the user's local settings
        - main.cpp runs the application
        - the rest are the CMakeLists.txt and the pages cpp and hpp folders including models
        - 



**README File** (`README.md`):
    - Include a **detailed README** in Markdown format with the following information:
        - **Team Members**: Full names and student IDs of each team member.
        - **Project Overview**: Brief description of the application, its purpose, and main features.
        - **Setup Instructions**: Step-by-step guide on how to compile, configure, and run the application on the FEPS Red Hat system.
        - **Dependencies**: List all libraries and dependencies required, including any setup steps if additional libraries beyond the standard Qt installation are needed.
        - **File Structure**: Outline the main structure of the application folder, explaining key folders and files.
        - **Known Issues**: Any known limitations or unresolved bugs should be documented in this section.


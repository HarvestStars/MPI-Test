# MPI Test Demo for Windows

Welcome to this repository! This demo shows how to create an MPI-based application on Windows using C++. It assumes you have some experience with Visual Studio. Let's get started step by step!

## Prerequisites

### 1. Install Visual Studio

Make sure you have installed Visual Studio on your Windows machine with the C++ development tools. If not, please follow the official guide [here](https://learn.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=vs-2022).

### 2. Install Microsoft MPI

Next, install the **Microsoft MPI Tool**, which provides the necessary C++ libraries and tools to implement MPI on Windows. [here](https://www.microsoft.com/en-us/download/details.aspx?id=105289)

### 3. Install CMake (Recommended)

To manage the build process more efficiently, it's recommended to use **CMake**. I've provided a `CMakeLists.txt` in this repository to facilitate cross-platform compilation in the future. You can download CMake from [here](https://cmake.org/download/).

## Step-by-Step Guide

Now, let's build the MPI demo using CMake:

1. **Download this repository** to your local machine.
2. Open the repository directory and create a new folder named `Build`.
3. Open a terminal in the `Build` directory and run the following command:

    ```bash
    cmake -B . -S ..
    ```

4. You will find a file with the `.vcxproj` suffix, usually named `ALL_BUILD.vcxproj`.
5. Open this `.vcxproj` file in **Visual Studio 2022** and build the project.
6. Go to the output folder, such as `Debug` or `Release`, where you will find the compiled executable file named `MPI-Test.exe`.
7. Finally, open a terminal (like PowerShell) and run the demo using the following command:

    ```bash
    mpiexec.exe -n 2 .\MPI-Test.exe
    ```

## Expected Output

After running the above command, you should see output similar to:

```plaintext
Process 0 sending number 42 to process 1  
Process 0 sent number 42 to process 1  
Process 1 received number 42 from process 0  

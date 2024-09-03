#include <mpi.h>  // Includes MPI library header files
#include <iostream>

int main(int argc, char** argv) {
    // Initialize MPI environment
    MPI_Init(&argc, &argv);

    // Get the total number of processes and the ID of the current process
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_size < 2) {
        std::cerr << "This program requires at least 2 MPI processes." << std::endl;
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (world_rank == 0) {
        // Process 0 sends an integer to process 1
        int number = 42;
        std::cout << "Process " << world_rank << " sending number " << number << " to process 1" << std::endl;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        std::cout << "Process " << world_rank << " sent number " << number << " to process 1" << std::endl;
    } else if (world_rank == 1) {
        // Process 1 receives the integer from process 0
        int number;
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "Process " << world_rank << " received number " << number << " from process 0" << std::endl;
    }

    // End MPI environment
    MPI_Finalize();

    return 0;
}
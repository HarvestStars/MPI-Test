#include <mpi.h>  // 包含 MPI 库头文件
#include <iostream>

int main(int argc, char** argv) {
    // 初始化 MPI 环境
    MPI_Init(&argc, &argv);

    // 获取进程总数和当前进程的 ID
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_size < 2) {
        std::cerr << "This program requires at least 2 MPI processes." << std::endl;
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (world_rank == 0) {
        // 进程 0 发送一个整数到进程 1
        int number = 42;
        std::cout << "Process " << world_rank << " sending number " << number << " to process 1" << std::endl;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        std::cout << "Process " << world_rank << " sent number " << number << " to process 1" << std::endl;
    } else if (world_rank == 1) {
        // 进程 1 接收来自进程 0 的整数
        int number;
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "Process " << world_rank << " received number " << number << " from process 0" << std::endl;
    }

    // 结束 MPI 环境
    MPI_Finalize();

    return 0;
}
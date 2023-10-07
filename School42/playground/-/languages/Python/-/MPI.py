from mpi4py import MPI
import numpy as np

# initialize MPI
comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

# set up the workload
num_simulations = 1000000
simulations_per_node = int(np.ceil(num_simulations / size))
start_index = simulations_per_node * rank
end_index = min(start_index + simulations_per_node, num_simulations)

# perform the simulations
results = []
for i in range(start_index, end_index):
    # run simulation i and append result to list
    result = run_simulation(i)
    results.append(result)

# gather the results from all nodes
all_results = comm.gather(results, root=0)

# process the results on the root node
if rank == 0:
    combined_results = []
    for result_list in all_results:
        combined_results.extend(result_list)
    # process combined_results

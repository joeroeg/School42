// long long time_in_millis() {
//     struct timeval now;
//     gettimeofday(&now, NULL);
//     return (now.tv_sec * 1000LL) + (now.tv_usec / 1000);
// }

// void ft_usleep(long long intended_duration_ms) {
//     long long start_time = time_in_millis();
//     usleep(intended_duration_ms * 1000); // Initial sleep
//     long long end_time = time_in_millis();
//     long long actual_sleep_duration = end_time - start_time;

//     // If we slept less than intended, adjust accordingly
//     while (actual_sleep_duration < intended_duration_ms) {
//         usleep((intended_duration_ms - actual_sleep_duration) * 1000);
//         end_time = time_in_millis();
//         actual_sleep_duration = end_time - start_time;
//     }
// }

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void		ft_usleep(long long time, philosopher_args *rules)
{
	long long i;

	i = timestamp();
	while (!(rules->dieded))
	{
		if (time_diff(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}

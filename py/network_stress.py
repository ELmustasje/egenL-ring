
import requests
import threading
import time

# Function to send HTTP requests


def send_requests(target_url, duration):
    """
    Sends continuous HTTP GET requests to a target URL for a specified duration.
    :param target_url: The URL to send requests to.
    :param duration: Time (in seconds) to keep sending requests.
    """
    end_time = time.time() + duration
    while time.time() < end_time:
        try:
            response = requests.get(target_url)
            print(f"Response Code: {response.status_code}")
        except requests.exceptions.RequestException as e:
            print(f"Error: {e}")

# Main function to start the stress test


def stress_test(target_url, num_threads, duration):
    """
    Starts a network stress test with multiple threads.
    :param target_url: The URL to target.
    :param num_threads: Number of threads to use.
    :param duration: Duration of the stress test in seconds.
    """
    threads = []
    print(f"Starting stress test on {target_url} with {num_threads} threads")

    for i in range(num_threads):
        thread = threading.Thread(target=send_requests, args=(target_url))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    print("Stress test completed.")


# User input for the stress test parameters
if __name__ == "__main__":

    stress_test(, threads, test_duration)

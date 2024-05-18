import ipaddress

def find_related_ips(ip_list, subnet_str):
    subnet = ipaddress.ip_network(subnet_str)
    related_ips = [ip for ip in ip_list if ipaddress.ip_address(ip) in subnet]
    return related_ips

# Example IP list
ip_list = [
    '192.168.1.10',
    '192.168.1.20',
    '192.168.2.10',
    '10.0.0.1',
    '172.16.0.1',
]

# Define the subnet
subnet_str = '192.168.1.0/24'

# Find related IPs
related_ips = find_related_ips(ip_list, subnet_str)
print(f"IP addresses in the subnet {subnet_str}: {related_ips}")

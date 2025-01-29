# Unreal ML Agents Documentation

You want to learn more about Unreal ML Agents? You are at the right place! This section will help you generate the
documentation so you can read it in your favorite browser. If you prefer not to generate it manually, all files in this
directory are plain text and can be viewed using any text file reader.

The documentation is written in **ReStructuredText (ReST)** and uses the **Sphinx documentation system**.

## Generating the Documentation Locally

To generate the documentation, follow these steps:

1. **Install Sphinx**:
   ```sh
   python -m pip install -r Docs/requirements.txt
   ```
2. **Navigate to the `Docs/` directory** in a terminal.
3. **Run the following command** to generate the HTML documentation:
   ```sh
   make html
   ```
   - On Windows, use:
     ```sh
     make.bat html
     ```

Once the documentation is fully generated, you can open the **index.html** page located at:

```
_build/html/index.html
```

This will open the documentation in your browser for easy reading.

## Additional Resources

For more details on Unreal ML Agents, check out:
- [Unreal ML Agents Documentation (Online)](https://unrealmlagents.readthedocs.io/en/latest/)

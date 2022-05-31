# Count HTML Tags

  **To Run Program:**\
  type 'make' in terminal and then type './main <form-al.html' in your terminal ('form-al.html' can be replaced with any html file existing/added in the folder, I just did not want to make it confusing by typing <<filename>).

  **Functions Explained:**
  I will start with my biggest function, the readFile function.
 
  This function is made to read the file, and then to find the tags inside the file starting with ‘<’ but excluding files that start with ‘<!’ or ‘</’. 
  After finding the tag read the tag until ‘>’, ‘space’ or ‘/’.
  
  The next function; updateTagCount updates the tag count. Basically, if the tag is found and existed before we just increment the count, if it didn’t exist before we add a new tag.
  
  The freeHeapMemory function frees the heap memory.
  
  The last function but not least; reportTags. This function prints out the tag names found and the number of occurrences.

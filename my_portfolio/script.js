
// Handle form submission (fake handler for demo purposes)
  document.getElementById('contactForm').addEventListener('submit', function (e) {
    e.preventDefault(); // Prevent actual form submission
    document.getElementById('successMessage').style.display = 'block';
    this.reset();
  });

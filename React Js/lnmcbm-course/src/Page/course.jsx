import { useState } from "react";

export default function CourseHeader() {
  const [activeSection, setActiveSection] = useState("create");

  return (
    <div className="p-6 max-w-3xl mx-auto">
      {/* Header Buttons */}
      <div className="flex flex-col sm:flex-row space-y-2 sm:space-y-0 sm:space-x-4 justify-center">
        <button 
          className={`w-full sm:w-auto px-4 py-2 rounded ${activeSection === "create" ? "bg-blue-500 text-white" : "bg-gray-200"}`} 
          onClick={() => setActiveSection("create")}
        >
          Create Course
        </button>
        <button 
          className={`w-full sm:w-auto px-4 py-2 rounded ${activeSection === "update" ? "bg-blue-500 text-white" : "bg-gray-200"}`} 
          onClick={() => setActiveSection("update")}
        >
          Update Course
        </button>
        <button 
          className={`w-full sm:w-auto px-4 py-2 rounded ${activeSection === "delete" ? "bg-blue-500 text-white" : "bg-gray-200"}`} 
          onClick={() => setActiveSection("delete")}
        >
          Delete Course
        </button>
      </div>

      {/* Content Section */}
      <div className="mt-4 p-6 border rounded shadow-lg">
        {activeSection === "create" && (
          <div>
            <h2 className="text-2xl font-semibold">Create a New Course</h2>
            <p className="text-gray-600">Fill in the details to create a course.</p>
          </div>
        )}
        {activeSection === "update" && (
          <div>
            <h2 className="text-2xl font-semibold">Update Course</h2>
            <p className="text-gray-600">Modify existing course details.</p>
          </div>
        )}
        {activeSection === "delete" && (
          <div>
            <h2 className="text-2xl font-semibold">Delete Course</h2>
            <p className="text-gray-600">Select a course to delete.</p>
          </div>
        )}
      </div>
    </div>
  );
}

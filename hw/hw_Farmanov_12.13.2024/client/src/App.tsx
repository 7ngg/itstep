import React, { useEffect, useRef, useState } from 'react';

interface User {
  id: string
  email: string
  firstname: string
  lastname: string
  age: number
  registryDate: string
}

function App() {
  const baseUrl = process.env.REACT_APP_API

  const searchRef = useRef<HTMLInputElement>(null);
  const [users, setUsers] = useState<User[]>([])

  const [popup, setPopup] = useState<boolean>(false)

  const [isError, setIsError] = useState<boolean>(false)
  const [errorText, setErrorText] = useState<string>("")

  const [userData, setUserData] = useState({
    email: '',
    firstname: '',
    lastname: '',
    age: 0,
  });

  const handleChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const { name, value } = e.target;
    setUserData((prev) => ({
      ...prev,
      [name]: value,
    }));
  };

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();

    const req = new Request(`${baseUrl}/users`, {
      method: 'POST',
      headers: {
        'Content-type': 'application/json',
      },
      body: JSON.stringify(userData),
    });

    fetch(req)
      .then(async (response) => {
        if (!response.ok) {
          const text = await response.text();
          throw new Error(text || `Error: ${response.status}`);
        }
        return response.json();
      })
      .then((data) => {
        setPopup(false);
      })
      .catch((err) => {
        console.error(err);
        setIsError(true);
        setErrorText(err.message);
      });
  };

  useEffect(() => {
    fetch(`${baseUrl}/users`)
      .then((resp) => {
        if (!resp.ok) throw new Error(`Error: ${resp.status}`);
        return resp.json();
      })
      .then((data) => {
        setUsers(data || [])
      })
      .catch((error) => console.error("Error fetching users:", error));
  }, [baseUrl]);

  const handleSearch = () => {
    const id = searchRef.current?.value.trim();
    if (!id) return;

    fetch(`${baseUrl}/users/${id}`)
      .then((resp) => {
        if (!resp.ok) throw new Error(`Error: ${resp.status}`);
        return resp.json();
      })
      .then((user) => {
        if (!user) {
          alert("User not found")
          return
        }

        setUsers([user])
      })
  };

  return (
    <>
      <div className="h-16 bg-stone-800 w-full flex items-center justify-center">
        <input
          ref={searchRef}
          className="outline-none w-9/12 bg-stone-600 px-2 py-1 rounded text-xl"
          placeholder="User ID"
        />
        <button
          onClick={handleSearch}
          className="ml-4 bg-blue-500 text-white px-4 py-1 rounded hover:bg-blue-600"
        >
          Search
        </button>
      </div>
      <div className="container mx-auto p-4">
        <h1 className="text-2xl font-bold mb-4">Users</h1>
        <div className="overflow-x-auto">
          <table className="table-auto w-full border-collapse border border-gray-300">
            <thead>
              <tr className="bg-gray-200 text-gray-700">
                <th className="border border-gray-300 px-4 py-2 text-left">ID</th>
                <th className="border border-gray-300 px-4 py-2 text-left">Email</th>
                <th className="border border-gray-300 px-4 py-2 text-left">First Name</th>
                <th className="border border-gray-300 px-4 py-2 text-left">Last Name</th>
                <th className="border border-gray-300 px-4 py-2 text-left">Registry Date</th>
              </tr>
            </thead>
            <tbody>
              {users.length > 0 ? (
                users.map((user) => (
                  <tr key={user.id} className="hover:bg-gray-100">
                    <td className="border border-gray-300 px-4 py-2">{user.id}</td>
                    <td className="border border-gray-300 px-4 py-2">{user.email}</td>
                    <td className="border border-gray-300 px-4 py-2">{user.firstname}</td>
                    <td className="border border-gray-300 px-4 py-2">{user.lastname}</td>
                    <td className="border border-gray-300 px-4 py-2">
                      {new Date(user.registryDate).toLocaleDateString()}
                    </td>
                  </tr>
                ))
              ) : (
                <tr>
                  <td
                    colSpan={5}
                    className="border border-gray-300 px-4 py-2 text-center text-gray-500"
                  >
                    No users found
                  </td>
                </tr>
              )}
            </tbody>
          </table>
        </div>
      </div>
      <div
        className="rounded-full bg-stone-800 w-12 h-12 text-white flex flex-col items-center text-4xl cursor-pointer hover:bg-stone-700 active:bg-stone-900 transition absolute bottom-5 right-5 select-none"
        onClick={() => setPopup(!popup)}>
        <i className='table-cell align-middle text-center'>+</i>
      </div>
      <form
        className={`${popup ? 'block' : 'hidden'
          } fixed top-0 left-0 w-full h-full bg-gray-500 bg-opacity-50 flex justify-center items-center`}
        onSubmit={handleSubmit}
      >
        <div className="bg-white w-[400px] p-6 rounded-lg shadow-lg">
          <h2 className="text-xl font-bold mb-4 text-center">Create User</h2>

          <label className="block text-gray-700 mb-2" htmlFor="email">
            Email
          </label>
          <input
            type="email"
            id="email"
            name="email"
            value={userData.email}
            onChange={handleChange}
            className="w-full p-2 mb-4 border border-gray-300 rounded-md"
            placeholder="Enter email"
            required
          />

          <label className="block text-gray-700 mb-2" htmlFor="firstname">
            First Name
          </label>
          <input
            type="text"
            id="firstname"
            name="firstname"
            value={userData.firstname}
            onChange={handleChange}
            className="w-full p-2 mb-4 border border-gray-300 rounded-md"
            placeholder="Enter first name"
            required
          />

          <label className="block text-gray-700 mb-2" htmlFor="lastname">
            Last Name
          </label>
          <input
            type="text"
            id="lastname"
            name="lastname"
            value={userData.lastname}
            onChange={handleChange}
            className="w-full p-2 mb-4 border border-gray-300 rounded-md"
            placeholder="Enter last name"
            required
          />

          <label className="block text-gray-700 mb-2" htmlFor="age">
            Age
          </label>
          <input
            type="number"
            id="age"
            name="age"
            value={userData.age}
            onChange={handleChange}
            className="w-full p-2 mb-4 border border-gray-300 rounded-md"
            placeholder="Enter age"
            required
          />

          <div className={`${isError ? 'block' : 'hidden'} text-red-500`}>
            {errorText}
          </div>

          <div className="flex justify-end">
            <button
              type="button"
              onClick={() => setPopup(false)}
              className="mr-4 text-gray-500 hover:text-gray-700"
            >
              Cancel
            </button>
            <button
              type="submit"
              className="bg-stone-800 text-white px-6 py-2 rounded-md hover:bg-stone-700"
            >
              Create User
            </button>
          </div>
        </div>
      </form>
    </>
  );
}

export default App;

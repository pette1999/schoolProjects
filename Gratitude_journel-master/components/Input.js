import { useState } from 'react'

export default function Input({ handleSubmit }) {
  const [value, setValue] = useState("")

  let submitForm = (e) => {
    e.preventDefault()
    handleSubmit(value)
    setValue("")
  }

  return (
    <form onSubmit={submitForm}>
      <input type="text" value={value} className="rounded px-3 py-2" onChange={(e) => setValue(e.target.value)}>

      </input>
      <button type="submit" className="bg-pink-300 rounded px-12 py-2">Save</button>
    </form>
  )
}
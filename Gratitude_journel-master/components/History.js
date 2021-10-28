export default function History({ gratitudes }) {
  return (
    <p className="text-white text-2xl"> Previously. you are grateful for 
      <span className="font-bold">
        {gratitudes.map(g => ' ' + g.entry).toString()}
      </span>
    </p>
  )
}